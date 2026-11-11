//GZ-J00085 贵阳市第二实验中学 杨浩然
#include <bits/stdc++.h>
using namespace std;
string n,m,a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>a>>m>>b;
	int k=0;
	if(n==m){
		cout<<1;
		k++;
		if(a[0]==b[0]&&a[1]==b[1]){
			cout<<1;
			k++;
			if(((a[2]>='A'&&a[2]<='C')&&(b[2]>='A'&&b[2]<='C'))||((a[2]>='D'&&a[2]<='F')&&(b[2]>='D'&&b[2]<='F'))){
				cout<<1;
				k++;
				if(((a[2]>='A'&&a[2]<='C')&&(a[2]-b[2]==1||b[2]-a[2]==1))||((a[2]>='D'&&a[2]<='F')&&(a[2]-b[2]==2||b[2]-a[2]==2))){
					cout<<1;
					k++;
				}
			}
		}
	}
	for(int i=0;i<4-k;i++){
		cout<<0;
	}
	return 0;
} 
