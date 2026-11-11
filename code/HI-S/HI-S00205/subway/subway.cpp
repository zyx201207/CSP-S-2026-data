#include<bits/stdc++.h>
using namespace std;
struct u{
	int st;
	int en;
};
long long a,b,c,d,e,q[100001];
u p[100001];
long long sum=0;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>a>>b>>c>>d>>e;
	for(int i=0;i<b;i++){
		int k;
		cin>>k;
		for(int i=0;i<k;i++){
			cin>>p[i].st>>p[i].en;
			sum+=p[i].en;
			
		}
	}
	for(int i=0;i<c;i++){
		cin>>q[i];
		sum+=q[i];
	}
	cout<<sum;
	return 0;
}
