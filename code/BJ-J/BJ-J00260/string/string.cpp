#include <bits/stdc++.h>
using namespace std;
struct duan{
	int a;
	char c;
}ld[200050];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int xs=1;xs<=n;xs++){
		cin>>ld[xs].a>>ld[xs].c;
	}
	int l=1,r=n;
	long long ans=0;
	while(l<r){
		if(ld[l].c!=ld[r].c){
			ans+=min(ld[l].a,ld[r].a);
		}
		if(ld[l].a>ld[r].a){
			ld[l].a-=ld[r].a;
			r--;
		}else if(ld[l].a<ld[r].a){
			ld[r].a-=ld[l].a;
			l++;
		}else{
			l++;
			r--;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
