#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],b[200005],x[100005];
char c[200005],b1[200005],x1[100005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	bool o=true;
	int m=0,j=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		if(c[i]!=c[i-1]){
			j++;
			b1[j]=c[i];
		}
		b[j]+=a[i];
		m+=a[i];
		if(c[i]!=c[i-1]){
			o=false;
		}
	}
	if(o==true){
		cout<<0<<endl;
		return 0;
	}
	int w;
	if(m%2==0){
		int u=0,i;
		for(i=1;;i++){
			if(u+b[i]<=m/2){
				u+=b[i];
				x[i]=b[i];
				x1[i]=b1[i];
			}
			else if(u+b[i]>m/2&&u!=m/2){
				x[i]=b[i]-(b[i]+u-m/2);
				b[i]=b[i]+u-m/2;
				x1[i]=b1[i];
				break;
			}
		}
		int p=1,y[100005];
		char y1[100005];
		for(int j=i;j>=1;j--){
			y[p]=x[j];
			y1[p]=x1[j];
			p++;
		}
		p=0;
		for(int j=i;;j++){
			p++;
			if(b1[i]==y1[p]&&b[i]==y[p]){
				continue;
			}
			if(b1[i]!=y1[p]){
				if(b[i]==y[p]){
					w+=b[i];
				}
			}
		}
	}
	cout<<w<<endl;
	return 0;
}
