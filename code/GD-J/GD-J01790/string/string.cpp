#include<bits/stdc++.h>
using namespace std;
int n,a[200010],k;
char c[200010];
long long s=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		//cout<<"\n";
		//cout<<a[i]<<c[i];
	}
	//for(int i=1;i<=20;i++) cout<<a[i]<<c[i]<<"\n"; 
	for(int i=1,j=n;i<j;){
		if(c[i]!=c[j]) s+=min(a[i],a[j]);
		/*if(i==80) cout<<k<<" "<<a[i]<<" "<<i<<"\n";
		if(i==81) cout<<k<<" "<<a[i]<<" "<<i<<"\n";
		if(i==82) cout<<k<<" "<<a[i]<<" "<<i<<"\n";
		if(i==83) cout<<k<<" "<<a[i]<<" "<<i<<"\n";
		if(i==84) cout<<k<<" "<<a[i]<<" "<<i<<"\n";*/
		if(a[i]<a[j]){
			k=a[j]-a[i];
			a[j]-=a[i];
			a[i]=0;
			i++;
		}
		else if(a[i]==a[j]){
			a[i]=0;
			a[j]=0;
			i++;
			j--;
			k=0;
		}
		else{
			k=a[i]-a[j];
			a[i]-=a[j];
			a[j]=0;
			j--;
		}
	}
	/*for(int i=1;i<=100;i++){
		cout<<a[i]<<c[i]<<"\n";
		if(a[i]!=0) cout<<i;
	}*/
	cout<<s;
	return 0;
}
