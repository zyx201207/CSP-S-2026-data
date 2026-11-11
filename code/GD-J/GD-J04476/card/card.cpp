#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll rd(){
	ll sign=1,res=0;char c=getchar();
	while(!isdigit(c)){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(isdigit(c)){
		res=res*10+c-'0';
		c=getchar();
	}
	return sign*res;
}
const int N=5e5+5;
int a[N],lst[N],b[N];
int ans[N];
int n,m;

void st1(){
	int cnt=1;
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i-1]){
			b[cnt++]=a[i];
		}
		lst[a[i]]++;
	}
	
	for(int i=1;i<=m;i++){
		ans[i]=ans[i-1]+lst[i];
		cout<<ans[i]<<" ";
	}
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	n=rd(),m=rd();
	bool subtask1=1;
	for(int i=1;i<=n;i++){
		a[i]=rd();
		if(i>=2&&a[i]<a[i-1]) subtask1=0;
	}
	if(subtask1){
		st1();
		return 0;
	}
	for(int i=n;i>=1;i--){
		if(lst[a[i]]==0){
			lst[a[i]]=i;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;){
			if(lst[a[j]]!=j) j=lst[a[j]];
			else{
				ans[a[j]]++;
				j++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

