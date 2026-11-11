#include<bits/stdc++.h>
using namespace std;
long long n,a[1000005],q,w,cnt,er;
string b[1000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(long long i=2;i<=n;i++){
		if(b[i]!=b[i-1]) er=1;
	}
	if(er==0){
		cout<<"0";
		return 0;
	}
	q=1,w=n;
	while(q<w){
			if(a[q]>a[w]){
				cnt=cnt+a[w];
				a[q]=a[q]-a[w];
				w--;
			}
			if(a[q]<a[w]){
				cnt=cnt+a[q];
				a[w]=a[w]-a[q];
				q++;
			}
			else{
				if(b[q]!=b[w])cnt=cnt+a[w];
				w--;
				q++;
			}
	}
	cout<<cnt;
	return 0;
}
