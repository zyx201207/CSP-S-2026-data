#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+100;
int a[maxn],station[maxn],times[maxn],planfirst[maxn],planlast[maxn];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++)
		cin>>a[i];
	for(int i=0;i<n;i++){
		int num=0;
		cin>>num;
		for(int j=0;j<num;j++){
			cin>>station[i]>>times[i];
		}
	} 
	for(int i=0;i<q;i++){
		cin>>planfirst[i]>>planlast[i];
		int v=planlast[i]-planfirst[i];
		int ans=a[planfirst[i]-1]+a[planlast[i]-1]+2*v*times[1];
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
