#include<bits/stdc++.h>
using namespace std;
long long int n,num=1,ans=0,bj=1;
struct str{
	long long int hand;
	long long int end;
	long long int sum;
	char c;
}a[200100];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n;
	
	for(int i=1;i<=n;i++){
		cin>>a[i].sum;
		cin>>a[i].c;
		a[i].hand=num;
		a[i].end=num+a[i].sum-1;
		num+=a[i].sum;
	}
	num-=1;
	int x=1,y=n;
	
	while(bj<=num){
		long long int jh;
		jh=num-a[y].hand+1;
		if(a[x].c!=a[y].c){
			ans+=min(a[x].end,jh)-bj+1;
		}
		if(a[x].end<jh){
			bj=a[x].end+1;
			x++;
		}else if(a[x].end==jh){
			bj=a[x].end+1;
			x++;
			y--;
		}else{
			bj=jh+1;
			y--;
		}
	}
	cout<<ans/2;
	
	cout.flush();
	fflush(stdout);
	fclose(stdout);
	fclose(stdin);
	
	return 0;
}
