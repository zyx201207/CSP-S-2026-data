#include<bits/stdc++.h>
using namespace std;
long long a[200001],ans;
int cnt,n,tmp,maxx;
string a1,a2,tmp1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	cin>>a[0]>>a1;
	for(int i=1;i<n;i++){
		cin>>tmp>>a2;
		if(a1==a2){
			a[cnt]+=tmp;
			continue;
		} 
		cnt++;
		a[cnt]=tmp;
		tmp1+=a2;
		a1=a2;
	}
	maxx=cnt;
	for(int i=0;i<=cnt;i+=0){
		if(i==maxx){
			break;
		}
		if(tmp1[i]==tmp1[maxx]){
			if(a[i]>a[maxx]){
				a[i]-=a[maxx];
				maxx--;
				continue;
			}
			if(a[i]<a[maxx]){
				a[maxx]-=a[i];
				i++;
				continue;
			}
			i++;
			maxx--;
			continue;
		}
		if(a[i]>a[maxx]){
			a[i]-=a[maxx];
			ans+=a[maxx];
			maxx--;
			continue;
		}
		if(a[i]<a[maxx]){
			a[maxx]-=a[i];
			ans+=a[i];
			i++;
			continue;
		}
		ans+=a[i];
		if(i+1==maxx){
			break;
		}
		i++;
		maxx--;
	}
	cout<<ans;
	return 0;
} 
