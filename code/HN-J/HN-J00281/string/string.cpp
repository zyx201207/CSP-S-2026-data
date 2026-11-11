#include<bits/stdc++.h>
using namespace std;
int n;
struct d{
	int m;
	char b;
}a[200005];
int k,h;
int l;
string c;
int cnt;
bool f;
int y;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].m>>a[i].b;
		l+=a[i].m;//输入 
	} 
	for(int i=0;i<n;i++){
		k=a[i].m;
		if(f==0){
			for(int j=0;j<k;j++){//第一组转录（边界） 
				c[j]=a[i].b;
				
				f=1;
			}
		}
		else {
			h+=a[i-1].m;
			for(int v=h;v<=h+k-1;v++){//其余转录 
				c[v]=a[i].b;
					
			}
		}
	}
	

	for(int i=0;i<(l-1)/2+1;i++){ 
		if(c[i]!=c[l-1-i]) cnt++;
	}
	cout<<cnt; 
	return 0;
} 
