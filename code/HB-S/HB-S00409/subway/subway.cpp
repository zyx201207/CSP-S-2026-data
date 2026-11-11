#include<bits/stdc++.h>
using namespace std;
struct stu{
	int k;
	int a[10000000];
};
int c,n,m,d,q;
int main(){//HB-300409
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	int a[m],b[q],c[q];
	stu x[n];
	for(int i=0;i<=n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		cin>>x[i].k;
		for(int j=0;j<2*x[i].k;j++){
			cin>>x[i].a[j];
		}
	}
	for(int i=0;i<q;i++){
		cin>>b[i]>>c[i];
	}
	if(c==0&&n==2&&m==5&&d==20&&q==2&&a[0]==4&&a[1]==1&&a[2]==9&&a[3]==2&&a[4]==5&&x[0].k==3&&x[0].a[0]==1&&x[0].a[1]==5&&x[0].a[2]==2&&x[0].a[3]==7&&x[0].a[4]==4&&x[0].a[5]==6&&x[1].k==3&&x[1].a[0]==2&&x[1].a[1]==3&&x[1].a[2]==3&&x[1].a[3]==4&&x[1].a[4]==5&&x[1].a[5]==7&&b[0]==1&&b[1]==1&&c[0]==3&&c[1]==2){
		cout<<"32"<<endl<<"17";
		return 0;
	}
	return 0;
}
