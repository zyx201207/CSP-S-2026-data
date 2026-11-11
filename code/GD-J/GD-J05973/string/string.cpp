#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int z,x[100005],c[100005],p=1,a=1,s=1,cnt=0,o;
	char x1[100005],c1[100005],o0;
	cin>>z;
	for(int i=1;i<=z/2;i++){
		cin>>x[i]>>x1[i];
	}
	if(z%2==1){
		cin>>o>>o0;
	}
	for(int i=z;i>=z-z/2+1;i--){
		cin>>c[p]>>c1[p];
		p++;
	}
	for(int i=1;i<=z;i++){
		if(x1[a]==c1[s]){
			if(x[a]=c[s]){
				a++;
				s++;
			}else if(x[a]>c[s]){
				x[a]-=c[s];
				s++;
			}else{
				c[s]-=x[a];
				a++;
			}
		}else{
			if(x[a]=c[s]){
				cnt+=x[a];
				cout<<x[a]<<x1[a]<<c[s]<<c1[s];
				a++;
				s++;
			}else if(x[a]>c[s]){
				cnt+=c[s];
				x[a]-=c[s];
				s++;
			}else{
				cnt+=x[a];
				c[s]-=x[a];
				a++;
			}
		}
		if(a==z/2+1){
			for(int j=s;j<=z/2;j++){
				cnt+=c[j];
			}
			cout<<"fwfwfw";
			break;
		}else if(s==z/2+1){
			for(int j=a;j<=z/2;j++){
				cnt+=x[j];
			}
			cout<<"fmfmfm";
			break;
		}
	}
	cout<<cnt;
    return 0;
}