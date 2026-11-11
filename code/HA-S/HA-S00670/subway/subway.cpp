#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,p;
int a[500005],s[500005];
struct node{
	int l,t;
}b[5005][5005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	int sum=0,ll=0,bbb=0;
	for(int i=1;i<=n;i++){
		int s;
		cin>>s;
		for(int j=1;j<=s;j++){
			cin>>b[i][j].l>>b[i][j].t;
			sum+=b[i][j].t;
			bbb=b[i][j].t;
		}
		if(s!=2){
			ll++;
		}
	}
	for(int i=1;i<=p;i++){
		int h,j;
		cin>>h>>j;
		if(ll==0){
			cout<<sum+a[h]+a[j]<<endl;
		}else{
			cout<<a[h]+a[j]+bbb*(j-h-1)<<endl;
		}
    }
	fclose(stdin);
	fclose(stdout);
	return 0;
}
