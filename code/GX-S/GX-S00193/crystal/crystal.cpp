#include<bits/stdc++.h>
using namespace std;
struct sj{
	int a[100000000005];
};
bool cmp(a &x,a&y){
	if(a.x!=a.y) return x<y;
}
struct ch{
	int xl[100000000005];
};
bool cmp(xl &x,xl &y){
	if(xl.x!=xl.y) return xl.x<xl.y;
}
int main{
freopen("crystal.in",'r',stdin);
freopen("crystal.out",'w',stdout);
    long long n,m,;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>j[i].a;
    }
    sort(a,a+n,cmp);
    for(int i=0;i<n;i++){
        ch[i]=a[i+1]-a[i];
        xl[i]=ch[i];
    }
    
    sort(xl,xl+n,cmp);
    int sum=1,yy=0;
    if(xl[0]<m){
		cout<<sum;
    } 
    for(int i=0;i<n;i++){
	    if(ch[i]==xl[i]&&m!=0){
		    yy=a[i+1]-a[i];
		    m-=yy;
		    sum+=1;
		}
		cout<<sum;
	}
    for(int i=n;i>0;i--){
	    if(ch[i]==xl[i]&&m!=0){
		    yy=a[i]-a[i-1];
		    m-=yy;
		    sum+=1;
		}
		cout<<sum;
	}
	if(n%2==0){
	    if(a[n/2]==a[(n/2)+1]{
			sum+=1;
	        if(m<xl[0]){
				cout<<sum;
	        }else{
	            if(a[n/2]-a[(n/2)-1]<a[(n/2)+1]-a[n/2]&&m>xl[0]){
					for(int i=n/2;i>0;i--){
		                 yy=a[i]-a[i-1];
						 m-=yy;
						 sum+=1;
		            }
		            cout<<sum;
	            }else{
					for(int i=n/2;i<n;i++){
		                 yy=a[i+1]-a[i];
						 m-=yy;
						 sum+=1;
		            }
		            cout<<sum;
	            
	            }
	            
	       }
	    }
   } 
    return 0;
}
