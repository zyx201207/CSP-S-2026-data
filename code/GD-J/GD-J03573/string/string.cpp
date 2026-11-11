#include<bits/stdc++.h>
#define inc(i,l,r) for(int i=l;i<=r;++i)
#define dec(i,r,l) for(int i=r;i>=l;--i)
#define ll long long
using namespace std;
const int N=2e5+10;
ll a[N];
char t[N];
ll mid=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	inc(i,1,n){
		cin>>a[i]>>t[i];
		mid=mid+a[i];
	}
	ll tot=0;
	if(mid&1){
		mid=(mid+1)/2;
		//cout<<mid<<"\n";
		ll left=1,right=n;
		ll l=0,r=0;
		ll position=0,p=0;
		while(p<mid){
			p+=a[++position];
		}
		p-=a[position];
		//cout<<position<<"\n";
		while(left<position&&right>position){
			if(l==0)l+=a[left];
			if(r==0)r+=a[right];
			if(t[left]==t[right]){
				ll g=min(l,r);
				l-=g;r-=g;
				if(l>0)right--;
				else if(r>0)left++;
				else right--,left++;
			}
			else{
				ll g=min(l,r);
				tot+=g;
				//cout<<tot<<"!\n";
				l-=g;
				r-=g;
				if(l>0)right--;
				else if(r>0)left++;
				else right--,left++;
			}
		}
		if(left==right){
			cout<<tot;
			return 0;
		}
		else if(left<position){
			int len=mid-p-1,len2=a[position]-(mid-p);
			ll g=min(len,len2);
			len-=g;
			len2-=g;
			if(t[position]!=t[left]){
				tot+=len2;
			}
			cout<<tot;
			return 0;
		}
		else{
			int len=mid-p-1,len2=a[position]-(mid-p);
			ll g=min(len,len2);
			len-=g;
			len2-=g;
			if(t[position]!=t[right])tot+=len;
			cout<<tot;
			return 0;
		}
	}
	else{
		ll le=mid/2,rr=le+1;
		ll left=1,right=n;
		ll l=0,r=0;
		ll position=0,p=0;
		while(p<le){
			p+=a[++position];
		}
		p-=a[position];
		if(p+a[position]==le){
			while(left<=position&&right>=position+1){
				if(l==0)l+=a[left];
				if(r==0)r+=a[right];
				if(t[left]==t[right]){
					ll g=min(l,r);
					l-=g;r-=g;
					if(l>0)right--;
					else if(r>0)left++;
					else right--,left++;
				}
				else{
					ll g=min(l,r);
					tot+=g;
					//cout<<tot<<"!\n";
					l-=g;
					r-=g;
					if(l>0)right--;
					else if(r>0)left++;
					else right--,left++;
				}
			}
			cout<<tot;
			return 0;
		}
		else{
			while(left<position&&right>position){
				if(l==0)l+=a[left];
				if(r==0)r+=a[right];
				if(t[left]==t[right]){
					ll g=min(l,r);
					l-=g;r-=g;
					if(l>0)right--;
					else if(r>0)left++;
					else right--,left++;
				}
				else{
					ll g=min(l,r);
					tot+=g;
				//cout<<tot<<"!\n";
					l-=g;
					r-=g;
					if(l>0)right--;
					else if(r>0)left++;
					else right--,left++;
				}
			}
			//cout<<r<<"!"<<endl;
			if(left==right){
				cout<<tot;
				return 0;
			}
			else if(left<position){
				int len=le-p-1,len2=a[position]-(rr-p);
				ll g=min(len,len2);
				len-=g;
				len2-=g;
				if(t[position]!=t[left]){
					tot+=len2;
				}
				cout<<tot;
				return 0;
			}
			else{
				int len=le-p-1,len2=a[position]-(rr-p);
				ll g=min(len,len2);
				len-=g;
				len2-=g;
				if(t[position]!=t[right]){
					tot+=len;
				}
				cout<<tot;
				return 0;
			}
		}
	}
}
