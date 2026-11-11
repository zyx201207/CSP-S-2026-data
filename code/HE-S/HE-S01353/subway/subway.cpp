#include <bits/stdc++.h>

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	
	long long checkpoints_num;
	long long lines_num;
	long long stations_num;
	long long station_line_max;
	long long plans_num;
	
	std::cin >> checkpoints_num >> lines_num >> stations_num >> station_line_max >> plans_num;
	
	std::vector<long long> walk_time(stations_num+1);
	for(long long i=1;i<=stations_num;i++){
		std::cin >> walk_time[i];
	}
	
	std::vector<std::vector<std::pair<long long, long long> > > g(stations_num+1,std::vector<std::pair<long long, long long> >());

	for(long long i=1;i<=lines_num;i++){
	 	long long stations_on_line_num;
	 	std::cin >> stations_on_line_num;
	 	
	 	std::vector< std::pair<long long,long long> > stations_on_line(stations_on_line_num+1);
		for(long long j=1;j<=stations_on_line_num;j++){
	 		std::cin >> stations_on_line[j].first >> stations_on_line[j].second;
		}
		
		for(long long j=1;j<=stations_on_line_num;j++){
			for(long long k=1;k<=stations_on_line_num;k++){
				if(stations_on_line[k].first == stations_on_line[j].first)
					continue;
				g[stations_on_line[j].first].push_back({stations_on_line[j].second + stations_on_line[k].second,stations_on_line[k].first});
			}
		}
	}
	
	std::vector<std::vector<long long> > dist(stations_num+1,std::vector<long long>(stations_num+1, INT_MAX/2));
	for(long long i=1;i<=plans_num;i++){
		long long start, end;
		std::cin >> start >> end;
		
		std::priority_queue<std::pair<long long, long long>,std::vector<std::pair<long long,long long> >,std::greater<std::pair<long long,long long> > > q;
		dist[start][start] = 0;
		q.push({0,start}); 
		while(!q.empty()){
			int d = q.top().first;
			int node = q.top().second;
			q.pop();
			
			for(auto v: g[node]){
				if(dist[start][v.second] > dist[start][node] + v.first) {
					dist[start][v.second] = dist[start][node] + v.first;
					q.push(v);
				}
			}
		}
		
		std::cout << walk_time[start] + walk_time[end] + dist[start][end] << "\n";
	}
	
	return 0;
}
