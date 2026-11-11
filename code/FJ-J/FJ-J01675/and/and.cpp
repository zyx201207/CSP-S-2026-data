#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int one[200005];
void cnto(long long num,int i){
	while(num){
		one[i]+=num%2;
		num/=2;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long ans=0;
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnto(a[i],i);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++)
			if(one[i]<=one[j]){
				if((one[i]==one[j])&&(a[i]>a[j])){
					break; 
				}
				swap(one[i],one[j]);
				swap(a[i],a[j]);
			}
	}
	ans=a[1];
	for(int i=2;i<=m;i++){
		ans&=a[i];
	}
	cout<<ans;
	return 0;
}
