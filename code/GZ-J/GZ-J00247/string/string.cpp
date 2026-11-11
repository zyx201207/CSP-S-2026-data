//GZ-J00247，秦泽锦玥，安顺开发区长水大洋实验学校 
#include<bits/stdc++.h>
using namespace std;
long long a[100000005],n,p=0,z=0;
string l,o;
int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>o[i];
	}
	int m=1;
	for(int i=1;i<=n;i++){
		p+=a[i];
		for(int j=m;j<=p;j++){
			l[j]=o[i];
		}
		m=p;
	}
	for(int i=1;i<=p/2;i++){
	int b=int(l[i]),c=int(l[p-i+1]);
	if(b==c)continue;
	else{
		z++;
	}
	}
	cout<<z;
	return 0;
}
