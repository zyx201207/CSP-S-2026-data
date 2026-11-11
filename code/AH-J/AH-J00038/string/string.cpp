#include <bits/stdc++.h>
using namespace std;
const int N=3e5+10;
using ll=long long;
struct Node{
	ll siz;
	char ch;
}a[N],t[N];
ll n,k,total,ind,ans;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char ch;
		cin>>x>>ch;
		k+=x;
		a[i].siz=x;
		a[i].ch=ch;
	}
	//cout<<k<<'\n';
	bool pd=false,pd2=false;
	for(int i=1;i<=n;i++){
		total+=a[i].siz;
		if(total==(k+1)/2){
			if(k%2==1){
				a[i].siz-=1;
			}
			pd=true,pd2=true;
		} 
		if(total>(k+1)/2&&k%2==0&&pd==false){
			ll lst=total-a[i].siz;
			t[++ind].siz=(k+1)/2-lst;
			t[ind].ch=a[i].ch;
			t[++ind].siz=a[i].siz-t[ind-1].siz;
			t[++ind].ch=a[i].ch;
			pd=true;
		}
		else if(total>(k+1)/2&&k%2==1&&pd==false){
			ll lst=total-a[i].siz;
			if((k+1)/2-lst-1!=0){
				t[++ind].siz=(k+1)/2-lst-1;
				t[ind].ch=a[i].ch;
				t[++ind].siz=a[i].siz-t[ind-1].siz-1;
				t[ind].ch=a[i].ch;
				pd=true;
			}
			else{
				//cout<<"sfsfd\n";
				t[++ind].siz=a[i].siz-1;
				t[ind].ch=a[i].ch;
				pd=true;
				pd2=true;
			}
			
		}
		else t[++ind]=a[i];
	}
	//for(int i=1;i<=n+pd-pd2;i++){
		//cout<<t[i].siz<<' '<<t[i].ch<<'\n';
	//}
	int l=1,r=n+pd-pd2;
	while(l<r){
		if(t[l].ch==t[r].ch){
			if(t[l].siz>t[r].siz){
				t[l].siz-=t[r].siz;
				r--;
			}
			else if(t[l].siz==t[r].siz){
				r--,l++;
			}
			else if(t[l].siz<t[r].siz){
				t[r].siz-=t[l].siz;
				l++;
			}
		}
		else{
			if(t[l].siz>t[r].siz){
				ans+=t[r].siz;
				t[l].siz-=t[r].siz;
				r--;
			}
			else if(t[l].siz==t[r].siz){
				ans+=t[l].siz;
				r--,l++;
			}
			else if(t[l].siz<t[r].siz){
				ans+=t[l].siz;
				t[r].siz-=t[l].siz;
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
}

