#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;


long long n,index,ans;
long long a[N],b[N];
char c[N],d[N];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b[i]>>d[i];
	} 
	for(int i=1;i<=n;i++){
		if(d[i]==c[index]){
			a[index]+=b[i];
		}else{
			a[++index]=b[i];
			c[index]=d[i];
		}
	}
	int i=1,j=index;
	//cout<<i<<" "<<j<<endl;
	//for(int i=1;i<=n;i++) cout<<a[i]<<" "<<c[i]<<endl;
	while(i<=j){
		//cout<<i<<" "<<j<<" a[i]:"<<a[i]<<" a[j]:"<<a[j]<<" "<<endl;
		if(c[i]!=c[j]){
			ans+=min(a[i],a[j]);
		}
		if(a[i]==a[j]){
			i++;
			j--;
		}
		else if(a[i]>a[j]){
			a[i]-=a[j];
			j--;
		}else{
			a[j]-=a[i];
			i++;
		}
		 
	}
	cout<<ans;
	return 0;
} 
