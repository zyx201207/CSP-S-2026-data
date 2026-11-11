#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int a[200003];
int s[200003];
char c[200003];
bool vis[200003];
int n,flag=0,ans,start,mid;

int fib(int p,int x){
	if(p==mid+1){
		return ans;
	}
	for(int i=n;i>=1;i--){
		if(p>=s[i-1]&&p<=s[i]){
			if(c[i]!=c[x]&&vis[i]==0){
				vis[i]=1;
				ans+=s[i]-p+1;
				x=2*mid-p;
				for(int j=1;j<=n;j++){
					if(x>s[j-1]&&x<=s[j]){
						x=j;
					}
				}
				fib(s[i]-1,x);
			}
		}
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	
	cin.tie(0);cout.tie();
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		s[i]=a[i]+s[i-1];
		if(c[i]==c[i-1]) flag=1;	
	}
	if(flag){
		cout<<"0"<<endl;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(s[n]%2==0){
		mid=s[n]/2;
	}
	else mid=s[n]/2+1;
	
	vis[1]=1;
	cout<<fib(n,1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
3
2 a
2 b
1 c


6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
