#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long cnt;
	int n,m; cin>>n>>m;
	if(n==1){
		cout<<0<<endl;
	}
	if(n==2){
		
	}
	else{
		int mid = (n/2);
		if((mid%3==0) || (mid%5==0) || (mid%7==0)|| (mid%9==0)){
			mid += 1;
		}
		vector<int> num(n);
		for(int i=1;i<=n;i++){
			cin>>num[i];
		}
		sort(num.begin(),num.end());
		while(m>0){
			for(int i:num){
					if(num[i] == num[i+1]){
						cnt++;
			}
			for(int i=1;i<=n;i++){
				if(num[i] == num[mid]){
					continue;
				}else{
					num[i] += mid-num[i];
					m = m-mid-num[i];
				}
				
				}
			
	}
}
		if(num[0] < 0){
			cnt+=2;
		}else{
			cnt-=1;
		}
}
	cout<<cnt<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
