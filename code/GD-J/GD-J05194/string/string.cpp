#include<bits/stdc++.h>
using namespace std;
struct q{
	long long l,r;
	char c;
};
q x[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long cnt=0;
	for(int i=0;i<n;i++){
		long long a1;
		char c1;
		cin>>a1>>c1;
		cnt+=a1;
		if(i==0){
			x[i].l=0;
			x[i].r=a1-1;
			x[i].c=c1;
		}
		else{
			x[i].l=x[i-1].r+1;
			x[i].r=x[i].l+a1-1;
			x[i].c=c1;
		}
	}
	int ans=0;
	for(int i=0;i<cnt/2;i++){
		int le=i,ri=cnt-i-1;
		char lt,rt;
		for(int j=0;j<n;j++){
			if(x[j].l<=le&&x[j].r>=le){
				lt=x[j].c;
			}
		}
		for(int j=0;j<n;j++){
			if(x[j].l<=ri&&x[j].r>=ri){
				rt=x[j].c;
			}
		}
		if(lt!=rt){
			ans++;
		}
	}
	cout<<ans;
}
