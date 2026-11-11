#include<bits/stdc++.h>
using namespace std;
long long a[20005];long long n,ans,h,num,nu[20005],j,cmp,as;
void bfs(int m,int x){

	if(m==0){

		num=max(num,ans);
		return  ;
	}
	for(int i=x;i<n;i++){if(h==m){
		ans=a[i];j++;
	}nu[h-m]=ans;

	ans=(ans&a[i]);

		bfs(m-1,x+1);
x++;
ans=nu[h-m];
	}

}
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
int m;
cin>>n>>m;
for(int i=0;i<n;i++){

	cin>>a[i];	
}ans=a[0];
h=m;
bfs(m,0);
cout<<num;
	return 0;
}
