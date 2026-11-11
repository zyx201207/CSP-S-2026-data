#include<bits/stdc++.h>
using namespace std;
int n;
int a[200005];
char c[200005];
long long x,y,mid=0,ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		mid+=a[i];
	}
	if(mid%2!=0)mid++;
	mid/=2;
	for(int i=0,j=n+1;x<=mid&&y<=mid;){
        if(x+a[i+1]>mid&&y+a[j-1]>mid){
        	ans+=max(mid-x-1,mid-y-1);
        	break;
		}
		if(x+a[i+1]==mid&&y+a[j-1]==mid){
		   if(c[i+1]!=c[j-1]){
		   	  ans+=max(a[i+1],a[j-1]);
		   }else{
		   	  ans+=max(a[i+1],a[j-1])-min(a[i+1],a[j-1]);
		   }
		   break;	
		}
		if(x==y){
			i++;
		    j--;
		    x+=a[i];
		    y+=a[j];
		    if(c[i]!=c[j]){
		   	    ans+=min(a[i],a[j]);
		    }
		}
		else if(x>y){
		    j--;
			y+=a[j];
			if(c[i]!=c[j]){
			    ans+=min(a[j],a[i]-a[j+1]);
			}
		}
		else{
	    	i++;
			x+=a[i];
			if(c[i]!=c[j]){
			    ans+=min(a[i],a[j]-a[i-1]);
			}	
		}
	}
	cout<<ans;
	return 0;
} 
