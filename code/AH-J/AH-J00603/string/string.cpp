#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
char b[200005];
long long ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
    	scanf("%d",&a[i]);
    	cin>>b[i];
	}
    int dx,dy,last=0;
    char ix,iy,cl;
    bool fl=true;
    for(int i=1,j=n;i<=j;i++,j--){
        dx=a[i];dy=a[j];
        ix=b[i];iy=b[j];
        if(last){
            if(fl){
                if(ix!=cl)ans+=last;
                dx-=last;
            }
            else{
                if(iy!=cl)ans+=last;
                dy-=last;
            }
        }
        if(dx>dy){last=dx-dy;cl=ix;}
        else {last=dy-dx;cl=iy;}
        if(ix!=iy)ans+=min(dx,dy);
    }
    printf("%lld",ans);
    return 0;
}
