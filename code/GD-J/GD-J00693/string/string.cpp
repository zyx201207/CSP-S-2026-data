#include <bits/stdc++.h>
using namespace std;

struct huiwen{
	long long acc;
	char ch;
};

int main(){
	freopen("string.in","r",stdin);
	freopen("string.ans","w",stdout);
	int n;
	cin>>n;
	vector<huiwen> a(n);
	int k=0;
	for(int i=1;i<=n;i++){
		char c;
		long long l;
		cin>>l>>c;
		if(c==a[k-1].ch) a[k-1].acc+=l;
		else{
			a[k].acc=l;
			a[k].ch=c;
			k++;
		}
	} 
	a.resize(k);
	if(k==1) cout<<"0";
	else{
		if(k==2 && a[0].acc==a[1].acc) cout<<a[1].acc;
		else{
			int ans=0;
			int l=0,r=k-1;
			while(l<r){
				if(a[l].ch==a[r].ch){
					if(a[l].acc>a[r].acc){
						a[l].acc-=a[r].acc;
						a[r].acc=0;
					}
					else{
						a[r].acc-=a[l].acc;
						a[l].acc=0;
					}
				}
				else{
					ans+=min(a[l].acc,a[r].acc);
					if(a[l].acc>a[r].acc){
						a[l].acc-=a[r].acc;
						a[r].acc=0;
					}
					else{
						a[r].acc-=a[l].acc;
						a[l].acc=0;
					}
				}
				if(a[l].acc==0) l++;
				if(a[r].acc==0) r--;
			}			
			cout<<ans;
		} 
	}
	return 0;
} 
