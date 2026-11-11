#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,a=1,cnt=1,sum=0,num[100005];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	for(int i=m;i>1;i--){
		for(int j=1;j<=m;j++){
			if(cnt!=m){
				if(num[i]==num[a]){
					sum++;
					break;
				}
				num[a]++;
			}
			a++;
			cnt++; 
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
