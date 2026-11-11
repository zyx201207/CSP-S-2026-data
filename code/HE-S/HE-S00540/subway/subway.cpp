#include<iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,sum1=0,sum2=0,sum3=0;
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++)
	cin>>sum1;
	for(int i=0;i<q;i++){
		cin>>sum3;
		for(int j=0;j<sum3*2;j++){
			int t;
			cin>>t;
			sum1+=t;
		}
		sum2=max(sum1,sum2);
	}
	for(int i=0;i<q;i++){
		cin>>sum1>>sum3;
		cout<<abs(sum1-sum3)*sum2+3<<'\n';
	}
	return 0;
} 
