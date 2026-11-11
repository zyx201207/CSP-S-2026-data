#include<bits/stdc++.h>
using namespace std;

#define int long long 

const int N=2e5+10;

struct str{
	char ch;
	int len;
	int l,r;
}a[N],b[N];

int n;

int tl[N];
char tc[N];

int ans;

signed main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	
	for(int i=1;i<=n;i++){
		cin>>tl[i]>>tc[i];
	}
	
	int sum=0;
	for(int i=1;i<=n;i++){
		a[i].ch=tc[i];
		a[i].len=tl[i];
				
		a[i].l=sum+1;
		a[i].r=sum+a[i].len;
		
		sum+=a[i].len;
	}	
	
	sum=0;
	for(int i=1;i<=n;i++){
		b[i].ch=tc[n-i+1];
		b[i].len=tl[n-i+1];
				
		b[i].l=sum+1;
		b[i].r=sum+b[i].len;
		
		sum+=b[i].len;
	}	
	
	/*for(int i=1;i<=n;i++){
		cout<<a[i].ch<<' '<<a[i].len<<' '<<a[i].l<<' '<<a[i].r<<'\n';
	}
	cout<<'\n';
	
	for(int i=1;i<=n;i++){
		cout<<b[i].ch<<' '<<b[i].len<<' '<<b[i].l<<' '<<b[i].r<<'\n';
	}
	cout<<'\n';*/
	
	int l=1,r=1;
	
	while(a[l].l<=sum/2&&b[r].l<=sum/2){
		
		//cout<<a[l].l<<' '<<a[l].r<<" ------ "<<b[r].l<<' '<<b[r].r<<'\n';
		
		if(a[l].ch==b[r].ch){
			if(a[l].r>b[r].r){
				a[l].l=b[r].r+1;
				r++;
			}
			else if(a[l].r<b[r].r){
				b[r].l=a[l].r+1;
				l++;
			}
			else if(a[l].r==b[r].r){
				l++,r++;
			}
			continue;
		}
		if(a[l].r>b[r].r){
			ans+=b[r].r-b[r].l+1;
			a[l].l=b[r].r+1;
			r++;
			//cout<<11111<<" "<<ans<<'\n';
		}
		else if(a[l].r<b[r].r){
			ans+=a[l].r-a[l].l+1;
			b[r].l=a[l].r+1;
			l++;
			//cout<<22222<<" "<<ans<<'\n';
		}
		else if(a[l].r==b[r].r){
			ans+=a[l].r-a[l].l+1;
			l++,r++;
			//cout<<33333<<" "<<sum<<'\n';
		}
	}
	
	cout<<ans;
	
	return 0;
}
/*
6 
3 a
1 b
3 b
2 a
1 c
2 b


4  
*/
/*
5
4 a
5 a
3 b
4 a
5 b


0
*/
