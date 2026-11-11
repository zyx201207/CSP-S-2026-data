#include<bits/stdc++.h>
using namespace std;
int n,ans=0;
long long cnt=0;
string a=" ";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		int aa;
		char b;
	scanf("%d%c",&aa,&b);
		cnt+=aa;
		for(int j=1;j<=aa;++j){
			a+=b;
		}
	}
    for(int i=1,j=cnt;i<=j;i++,j--){
    	if(a[i]!=a[j])ans++;
    }
    //cout<<a;
    printf("%d",ans);
    return 0;
}

