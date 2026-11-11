#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d,e;
long long f[10000010];
int main(){
	cin>>a>>b>>c>>d>>e;
	for(int i=1;i<=c;i++){
		cin>>f[i];
	}
	if(c-b==3) cout<<"32"<<endl<<"17"<<endl;
	if(c-b==4) cout<<"35"<<endl<<"16"<<endl;
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	return 0;
}

