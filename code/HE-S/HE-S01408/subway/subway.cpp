#include<bits/stdc++.h>
using namespace std;
long long kou[500005],tai[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long sum=0;
	int c,n,m,d,q,num,hao,stt,endd;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>kou[i];
	}
	
	for(int i=1;i<=n;i++){
		cin>>num;
		for(int j=1;j<=num;j++){
			cin>>hao>>tai[j];
			sum=sum+tai[j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>stt>>endd;
		sum=sum+kou[stt]+kou[endd];
		cout<<sum<<endl;
	}

	
	return 0;
}
