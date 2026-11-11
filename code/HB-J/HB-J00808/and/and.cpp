#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5,INF=-0x7f7f7f;
int n,m;
int a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("ans.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
        sort(a+1,a+1+n);
        cout<<a[1];
        return 0;
	}
	if(m==n){
        int sum=a[1];
        for(int i=1;i<=n;i++){
            sum&=a[i];
            cout<<sum<<endl;
        }
        cout<<sum;
        return 0;
	}
	int maxx=INF;
	if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                maxx=max(maxx,a[i]&a[j]);
            }
        }
        cout<<maxx;
        return 0;
	}
	fclose(stdin);
	fclose(stdout);s
	return 0;
}
