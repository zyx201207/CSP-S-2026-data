#include<bits/stdc++.h>
using namespace std;
string s;
char b[20010];
long long n,a[20010],cnt,f,m,c;
int main(){
    //freopen("string.in","r",stdin);
    //freopen("string.out","w",stdout);
    cin>>n;
    for(int i =0;i<n;i++){
    	cin>>a[i]>>b[i];
		}
		m =n-f-1;
		while(f<m){
			long long k = min(a[f],a[m]);
			if(b[f]!=b[m]){
				cnt+=k;
			}
				a[m]-=k;
				a[f]-=k;
				if(a[f]==0) f++;
				if(a[m]==0) m--;
		}
		cout<<cnt;
    return 0;
}
