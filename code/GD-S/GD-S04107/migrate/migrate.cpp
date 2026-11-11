#include<bits/stdc++.h>
using namespace std;
//
long long c,t,n,d;
vector<long long> x(2e6);
int check(long long a){
	deque<pair<long long,long long>> q;
	q.clear();
	q.push_back(pair<long long,long long>{a,0});
	vector<long long> cnt(n,0),len(n,-1);
	while(q.size()>0){
		pair<long long,long long> t1=q.front();
//		cout<<t1.first<<t1.second<<"->";//
//		if(len!=-1&&t1.second!=len){
////			cout<<"out1\n";//
//			return cnt==2;
//		}
		q.pop_front();
//		if(t1.first==b){
//			cnt++;
//			len=t1.second;
//			if(cnt>2){
////				cout<<"out2\n";//
//				return 0;
//			}
//		}
		if(t1.first!=a&&(len[t1.first]==-1||((len[t1.first])==(t1.second)))){
//			cout<<"("<<t1.first<<")";//
			cnt[t1.first]++;
			len[t1.first]=t1.second;
		}
		else if(t1.first!=a){
//			cout<<"out1\n";//
			continue;
		}
		for(long long i=t1.first+1;i<n;i++){
			if(x[i]-x[t1.first]<=d){
//				cout<<i<<" ";//
				q.push_back(pair<long long,long long>{i,t1.second+1});
			}
			else{
				break;
			}
		}
//		cout<<endl;//
	}
//	cout<<"out3\n";//
	int cnt2=0;
	for(int i=a+3;i<n;i++){
		if(cnt[i]==2){
			cnt2++;
		}
	}
	return cnt2;
}
//
int main(){
	ifstream in("migrate.in");
	ofstream out("migrate.out");
	//
	in>>c>>t;
	for(long long i_=0;i_<t;i_++){
		in>>n>>d;
		for(long long i=0;i<n;i++){
			in>>x[i];
		}
		if(c==11|c==12){
			long long di=x[1]-x[0];
			long long a=d/di;
			out<<((a-1>0)?max(n-2*a+1,(long long)(0)):0)<<'\n';
//			printf("%d %d %d %d %d\n",d,di,a,n,(a-1>0?max(n-2*a+1,(long long)(0)):0));
			continue;
		}
		long long cnt=0;
		for(long long i=0;i<n;i++){
//			for(long long j=i+3;j<n;j++){
//					cout<<i<<":\n";//
				cnt+=check(i);
//			}
		}
		out<<cnt<<'\n';
	}
	return 0;
}
