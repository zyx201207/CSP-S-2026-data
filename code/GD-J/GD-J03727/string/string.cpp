#include<bits/stdc++.h>
using namespace std;
long long n,num[200010],st,ans,s;
char a[200010];
bool ok=true;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num[i]>>a[i];
		if(i>1) if(a[i]!=a[i-1]) ok=false;
		s+=num[i];
	}
	if(ok){
		cout<<0;
		return 0;
	}
	for(int i=1,j=n;;){
		if(num[i]>num[j]){
			if(a[i]==a[j]) num[i]-=num[j];
			else ans+=num[j];
			st+=num[j];
			if(st*2>=s&&a[i]!=a[j]){
				ans-=num[j];
				st-=num[j];
				ans+=s/2-st;
				break;
			}
			j--;
		}
		else if(num[i]==num[j]){
			if(a[i]!=a[j]){
				ans+=num[i];
			}
			st+=num[i];
			if(st*2>=s&&a[i]!=a[j]){
				st-=num[i];
				ans-=num[i];
				ans+=s/2-st;
				break;
			}
			i++;
			j--;
		}
		else{
			if(a[i]==a[j]) num[j]-=num[i];
			else ans+=num[i];
			st+=num[i];
			if((st*2>=s||(s%2==1&&st*2>=s-1))&&a[i]!=a[j]){
				ans-=num[i];
				st-=num[i];
				ans+=s/2-st;
				break;
			}
			i++;
		}
		
	}
	cout<<ans;
	return 0;
}
