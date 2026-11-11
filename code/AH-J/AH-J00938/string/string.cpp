#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,ans;
struct N{
    ll num;
    char word;
}a[1000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].word;
	}
	ll i=1,j=n;
	while(i<=j){
		if(a[i].word==a[j].word){
			if(a[i].num>a[j].num){
				a[i].num-=a[j].num;
				a[j].num=0;
				j--;
			}
			else if(a[i].num==a[j].num){
				a[i].num=0;
				a[j].num=0;
				i++,j--;
			}
			else{
			    a[j].num-=a[i].num;
			    a[i].num=0;
			    i++;
		    }
	    }
		else{
			ans+=min(a[i].num,a[j].num);
			if(a[i].num>=a[j].num){
				a[i].num-=a[j].num;
				a[j].num=0;
				j--;
			}
			else if(a[i].num==a[j].num){
				ans+=a[i].num;
				a[i].num=0;
				a[j].num=0;
				i++,j--;
			}
			else{
			    a[j].num-=a[i].num;
			    a[i].num=0;
			    i++;
			}			
		}
	}
	cout<<ans;
	return 0;
}
