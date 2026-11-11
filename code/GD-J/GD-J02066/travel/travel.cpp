#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	char a[4],b[4];
	cin>>c1>>a>>c2>>b;
	if(c1==c2){
		cout<<1;
		if(a[0]==b[0]&&a[1]==b[1]){
			cout<<1;
			int sit1=a[2]-'A'+1;
			int sit2=b[2]-'A'+1;
			if(sit1>=1&&sit1<=3&&sit2>=1&&sit2<=3){
				cout<<1;
				if(abs(sit1-sit2)==1){
					cout<<1;
				}else cout<<0;
			}else if(sit2==4&&sit1==5 || sit1==4&&sit2==5){
				cout<<11;
			}else cout<<0<<0;
		}else cout<<0<<0<<0;
	}else cout<<0<<0<<0<<0;
	return 0;
}
