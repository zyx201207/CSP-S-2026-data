#include<bits/stdc++.h>
using namespace std;
int a[200005];
char b[200005];
int main(){
	freopen("string","r",stdin);
	freopen("string","w",stdout);
	int n;
	cin>>n;
	int q=0,w=n-1;
	char x;
	long long s=0,t=0;
	bool p=0;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	x=b[0],t=a[0];
	while(q!=w&&q<w){
		if(b[q]==b[w]&&t==0){
			x=b[q];
			if(a[q]>a[w]){
				w--;
				t=a[q]-a[w];
				p=1;
			}else	if(a[q]==a[w]){
				q++;
				w--;
			}else{
				q++;
				t=a[w]-a[q];
				p=0;
			}
		}else	if(!p){
			if(x==b[w]){
				if(t>a[w]){
					t-=a[w];
					w--;
				}else	if(t<a[w]){
					t=a[w]-t;
					q++;
					p=1;
				}else{
					q++;
					w--;
					x=b[q];
					t=a[q];
				}
			}else{
				if(t>a[w]){
					t-=a[w];
					s+=a[w];
					w--;
				}else	if(t<a[w]){
					s+=t;
					t=a[w]-t;
					q++;
					x=b[w];
					p=1;
				}else{
					s+=t;
					q++;
					w--;
					x=b[q];
					t=a[q];
				}
			}
		}else{
			if(x==b[q]){
				if(t>a[q]){
					t-=a[q];
					q++;
				}else	if(t<a[q]){
					t=a[q]-t;
					q++;
					p=0;
				}else{
					q++;
					w--;
					x=b[q];
					t=a[q];
					p=0;
				}
			}else{
				if(t>a[q]){
					t-=a[q];
					s+=a[q];
					q++;
				}else	if(t<a[q]){
					s+=t;
					t=a[q]-t;
					w--;
					x=b[q];
					p=0;
				}else{
					s+=t;
					q++;
					w--;
					x=b[q];
					t=a[q];
					p=0;
				}
			}
		}
	}
	cout<<s;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
