#include<bits/stdc++.h>
using namespace std;
struct p{
	long long a;
	string ch;
}b[200005],mx,q[1000005]; 
int n,m;
void zf(long long z,int zi){
	long long zs=0;
	bool za[1000000];
	while(z>0){
		if(z%2==1) za[zs]=1;
		else za[zs]=0;
//		cout<<zs<<" "<<za[zs]<<endl;
		zs++;
		z/=2;
	}
	for(int i=zs-1;i>=0;i--){
//		cout<<za[i]<<endl;
		if(za[i]==1) b[zi].ch+='1';
		else b[zi].ch+='0';
	}
}
void fds(int ki,string str,int last){
	for(int i=last;i<=n;i++){
		int mi;
		if(b[i].ch.length()>=str.length()) mi=str.length();
		else mi=b[i].ch.length();
		for(int j=0;j<=mi;j++){
			if(b[i].ch[j]=='1'&&str[j]=='1'){
				
			} 
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>b[i].a;
		zf(b[i].a,i);
	}
	for(int i=1;i<=n;i++){
		fds(1,b[i].ch,1);
	}
	return 0;
} 
