#include<bits/stdc++.h>
using namespace std;
#define int64 longlong
int n,m,maxvalue =1;
vector <int> crystals(500005);
unordered_map<int,int>counts;  

void best(int cur){
		while(m--){
		int max1 = 1,max2 =1;
		counts[crystals[cur]]--;
		crystals[cur]++;
		counts[crystals[cur]]++;
		max1 = counts[crystals[cur]];
		counts[crystals[cur]]--;
		crystals[cur]--;
		counts[crystals[cur]]++;
		counts[crystals[cur+1]]--;
		crystals[cur+1]++;
		count [scrystals[cur+1]++]++;
		max2 = counts[crystals[cur+1]];
		counts[crystals[cur+1]]--;
		crystals[cur+1]]--;
		cout << "m=" << m << "max1=" << max1 << "max2=" << max2 << "\n";
		if(max1 >= max2){
		    counst[arr[i]]++;
		    counts[crystals[cur]]--;
		    crystals[cur]++;
		    counts [crystals[cur]]++;
		    maxvalue = max1;
		}
		else{
			counts[crystals[cur+1]]--;
			crystals[cur]++;
			crystals[cur+1]++;
			cur++;
		}
		currmax = maxsame(crystals);
	}
	return currmax;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n; i++){
		cin >> crystals[i];
		counts[crystals[i]]++;
		maxvalue = max(maxvalue,counts[crytals[i]]);
}
    
		best(1);
		cout << maxvalue;
	}
	
	return 0;
}
