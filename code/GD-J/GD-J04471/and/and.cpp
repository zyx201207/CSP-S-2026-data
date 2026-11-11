
#include <bits/stdc++.h>
using namespace std;


int n,m,num,sum[35];
long long str,maxs = 0,s[100005],maxn;
bool mapnum[100005];
vector<long long> maxl;

bool stu(long long a){
	int s = maxs;
	while(s--){
		a /= 2;
//		cout << 's' << endl;
	}
	return a % 2;
}

void maxnum(long long nums,int dp){
	if(!dp){
		maxn = max(maxn,nums);
	}
	else{
		for(int i = 0;i < maxl.size();i++){
			if(mapnum[i] == 0){
				mapnum[i] = 1;
				maxnum(maxl[i] & nums,dp-1);
				mapnum[i] = 0;
			}
		}
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 0;i < n;i++){
		cin >> s[i];
		str = s[i];
		num = 0;
		while(str){
			if(str % 2 == 1)
				sum[num]++;
			num++;
			str /= 2;
		}
	}
	for(int i = 0;i < 32;i++){
		if(sum[i] >= m){
			maxs = i;
		}
	}
	for(int i = 0;i < n;i++){
		if(stu(s[i])){
			maxl.push_back(s[i]);
		}
	}
	
	
	
	if(maxl.size() == m){
		maxn = maxl[0];
		for(int i = 1;i < maxl.size();i++){
			maxn = (maxn & maxl[i]);
		}
	}
	else{
		for(int i = 0;i < maxl.size();i++){
			mapnum[i] = 1;
			maxnum(maxl[i],m-1);
			mapnum[i] = 0;
		}
//		
//		
//		for(int i = 0;i < 32){
//			sum[i] = 0;
//		}
//		for(int i = 0;i < maxl.size();i++){
//			str = maxl[i];
//			num = 0;
//			while(str){
//				if(str % 2 == 1)
//					sum[num]++;
//				num++;
//				str /= 2;
//			}
//		}
//		for(int i = 0;i < 32;i++){
//			if(sum[i] >= m){
//				maxs = i;
//			}
//		}
//		for(int i = 0;i < n;i++){
//			if(stu(s[i])){
//				maxl.push_back(s[i]);
//			}
//		}
	}
	cout << maxn;
	return 0;
}
