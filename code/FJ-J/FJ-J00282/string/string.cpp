#include<bits/stdc++.h>
using namespace std;
long long jdz(long long a){
	if(a<0){
		a=-a;
	}return a;
}
char l[200005];long long ms[200005],me[200005],ans=0;
int main(){
	ios::sync_with_stdio(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,th=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>me[i]>>l[i];th+=me[i];
		me[i]+=th-me[i];
		ms[i]=me[i-1];
	}
	long long h=0;
	for(int i=1;i<=n;i++){
		if(ms[i]<=(th+1)/2&&me[i]>=(th+1)/2){
			h=i;
			//ans+=jdz(me[i]-(th+1)/2-((th+1)/2)-ms[i]);
			if(me[i]-(th+1)/2>(th+1)/2-ms[i]){
				ms[i]=(th+1)/2+me[i]-(th+1)/2-((th+1)/2)-ms[i];
			}
			break;
		}
	}
	for(int i=1,j=n-i+1;i<=h&&j>=h;){int p=1;
	    if(i>h||j<h){
			break;
		}
		if(me[i]-ms[i]>me[j]-ms[j]&&l[i]!=l[j]){
			ans+=me[j]-ms[j];p=0;
			ms[i]+=me[j]-ms[j];j--;
		}else if(l[i]!=l[j]&&me[i]-ms[i]<me[j]-ms[j]){
			ans+=me[i]-ms[i];p=0;
			me[j]-=me[i]-ms[i];i++;
		}else if(l[i]!=l[j]&&me[i]-ms[i]==me[j]-ms[j]){
			ans+=me[i]-ms[i];p=0;
			i++;
			j--;
		}
		if(p){
			if(me[i]-ms[i]>me[j]-ms[j]){
				ms[i]+=me[j]-ms[j];j--;
			}else if(me[i]-ms[i]<me[j]-ms[j]){
				me[j]-=me[i]-ms[i];i++;
			}else{
				i++;
				j--;
			}
		}
		
		
	}
	cout<<ans;
	return 0;
}
