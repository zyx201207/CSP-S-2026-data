#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int num;
	char c;
}a[200010];
int n,lensum[200010],lensum2[200010],csum[200010][26],ans=0,zzz=0;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].c;
		lensum[i]=lensum[i-1]+a[i].num;
		zzz+=a[i].num;
	}
	for(int i=n;i>=1;i--){
		lensum2[i]=lensum2[i+1]+a[i].num;
	}
	for(int i=0;i<26;i++){
		for(int j=1;j<=n;j++){
			csum[j][i]=csum[j-1][i];
			if(a[j].c==char(i+'a')){
				csum[j][i]+=a[j].num;
			}
		}
	}
	//for(int i=1;i<=n;i++)cout<<csum[i][0]<<' ';
	//cout<<endl;
	int z=0,more=0;
	for(int i=n;i>=1;i--){
		int t=0;
		int x=lower_bound(lensum+1,lensum+n+1,lensum2[i])-lensum;
		if(lensum[x]==lensum2[i]){
			t=csum[x][a[i].c-'a']-csum[z][a[i].c-'a'];
			if(a[z].c==a[i].c){
				t+=more;
			}
		}
		else{
			t=csum[x-1][a[i].c-'a']-csum[z][a[i].c-'a'];
			if(a[z].c==a[i].c){
				t+=more;
			}
			if(a[x].c==a[i].c){
				t+=lensum2[i]-lensum[x-1];
			}
		}
		ans+=t;
		//cout<<t<<endl;
		z=x;
		more=lensum[x]-lensum2[i];
	}
	cout<<(zzz-ans)/2;
	return 0;
}
