#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,a[N],ma,sam=1;
char c[N];	
long long int sum=0,_find=0,k=0;
void _move(long long int x,int val){
	for(int i=n;i>=x+1;i--)a[i+1]=a[i];
	a[x+1]=val;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%s",&a[i],&c[i]);
		if(i>=2&&c[i]!=c[i-1])sam=0;
		ma=max(ma,a[i]);
		sum+=a[i];
	}if(ma==1){
		long long int sum;
		for(int i=1;i<=n/2;i++){
			if(c[i]!=c[n-i+1])sum++;
		}cout<<sum;
		return 0;
	}
	if(sam==1){
		cout<<0;
		return 0;
	}


	for(int i=1;i<=n;i++){
		_find+=a[i];
		if(_find>=(sum/2)){
			k=i;
			break;
		}
	}sum=0;
	if(n%2==0){
		for(int i=1,j=n;i<=k,j>k;){	
			int mi=min(a[i],a[j]);
				a[i]-=mi;
				a[j]-=mi;
			if(c[i]==c[j]);
			else sum+=mi;
				if(a[i]==0)i++;
				if(a[j]==0)j--;
			}
		printf("%lld",sum);
		return 0;
	}
	else{
		a[k]-=(_find-sum/2);
		_move(k,_find-sum/2);
			for(int i=1,j=n;i<=k,j>k;){	
			int mi=min(a[i],a[j]);
				a[i]-=mi;
				a[j]-=mi;
			if(c[i]==c[j]);
			else sum+=mi;
				if(a[i]==0)i++;
				if(a[j]==0)j--;
			}
		printf("%lld",sum);
		return 0;
	}
	return 0;
}
