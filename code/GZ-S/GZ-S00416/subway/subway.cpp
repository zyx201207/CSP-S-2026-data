//GZ-S00416 遵义市第十二中学 罗琪明 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	long long a,b,c,d,e,f,g;
	vector<long long>m(2000);
	vector<long long>nk(2000);
	
	cin>>a>>b>>c>>d>>e;
	for(int i=0;i<=b;i++){
		cin>>nk[i];
	}
	for(int j=0;j<=b;j++){
		for(int p=0;p<=b;p++){
			cin>>nk[j];
		}
	}
	freopen("subway.out","w",stdout);

	fclose(stdin);
	fclose(stdout);
}

