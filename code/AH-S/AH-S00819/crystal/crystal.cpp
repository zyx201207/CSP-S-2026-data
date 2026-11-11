#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,a[1001];
	int sum,sum1,sum2,cha1,cha2;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		sum+=a[i];
		cha1=sum/n;
		if(cha1-a[i]>=0){
			cha2=a[i];
			for(int i=1;i<=n;i++){
				int x=abs(cha2-a[i]);
				if(x<=m){
					sum1+=x;
					if(sum1<=m){
						sum2++;
					}
				}
			}
		}
	}	
	cout<<sum2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
