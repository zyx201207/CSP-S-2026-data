#include<bits/stdc++.h>
using namespace std;
const int MAXN=2*10e5+5;
#define ll long long
ll n,m,answer;
ll a[MAXN],ans[MAXN];
ll m1[MAXN],m2[MAXN];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}if(m==1){
		sort(a+1,a+1+n);
		int i=0;
		while(a[n]!=0){
			i++;
			m1[i]=a[n]%2;
			a[n]/=2;	
		}
		for(int q=1;q<=i;q++){
			answer+=ans[q]*pow(2,q-1);
		}
		cout<<answer<<'\n';
	}else if(m==2){
		sort(a+1,a+1+n);
		int i=0;
		while(a[n]!=0){
			i++;
			m1[i]=a[n]%2;
			a[n]/=2;	
		}	
		int j=0;
		while(a[n-1]!=0){
			j++;
			m2[j]=a[n-1]%2;
			a[n-1]/=2;
		}
		int k=min(i,j);
		for(int q=1;q<=k;q++){
			ans[q]=m1[q]&&m2[q];
		}
		for(int q=1;q<=k;q++){
			answer+=ans[q]*pow(2,q-1);
		}
		cout<<answer<<'\n';
	}
	return 0;
}

