#include<bits/stdc++.h>
using namespace std;
long long n,m,sum=0;
struct mp{
    long long l,r,len;
    char w;
}a[200050];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	//long long t=200000000000000;
	//cout<<t;
	cin>>n;
	long long x;
	for(int i=1;i<=n;i++){
        cin>>x>>a[i].w;
        a[i].l=sum+1;
        a[i].r=sum+x;
        a[i].len=a[i].r-a[i].l+1;
        sum+=x;
	}
	long long mid=sum/2,stl,str,ans=0;
	if(sum%2==0){
        for(int i=1;i<=n;i++){
            if(a[i].l<=mid&&a[i].r>mid){
                if(mid-a[i].l+1>a[i].r-mid){
                    a[i].r=mid-a[i].r+mid;
                    stl=i,str=i+1;
                }
                if(mid-a[i].l+1<a[i].r-mid){
                    a[i].l=mid+mid-a[i].l+2;
                    stl=i-1,str=i;
                }if(mid-a[i].l+1==a[i].r-mid){
                    stl=i-1,str=i+1;
                }
            }if(a[i].l==mid+1){
                stl=i-1,str=i;
            }if(a[i].r==mid){
                stl=i,str=i+1;
            }
        }
        //cout<<stl<<str<<endl;
                //cout<<mid-a[stl].l+1<<a[str].r-mid<<endl;
            while(stl>=1&&str<=n){
                if(mid-a[stl].l+1>a[str].r-mid){
                    if(a[stl].w!=a[str].w){
                        ans+=a[str].len;
                    }
                    a[stl].r=mid-a[str].r+mid;
                    str+=1;
                }
                //cout<<mid-a[stl].l+1<<a[str].r-mid<<endl;
                if(mid-a[stl].l+1<a[str].r-mid){
                    if(a[stl].w!=a[str].w){
                        ans+=a[stl].len;
                    }
                    a[str].l=mid+mid-a[stl].l+2;
                    stl-=1;
                }
                if(mid-a[stl].l+1==a[str].r-mid){
                    if(a[stl].w!=a[str].w){
                        ans+=min(a[stl].len,a[str].len);
                    }
                    stl-=1,str+=1;
                }
            }
            if(ans<mid)cout<<ans;
            else cout<<mid;
	}
	if(sum%2==1){
        mid+=1;
        for(int i=1;i<=n;i++){
            if(a[i].l<mid&&a[i].r>mid){
                if(mid-a[i].l>a[i].r-mid){
                    a[i].r=mid-a[i].r+mid;
                    stl=i,str=i+1;
                }
                if(mid-a[i].l<a[i].r-mid){
                    a[i].l=mid+mid-a[i].l+1;
                    stl=i-1,str=i;
                }
            }if(a[i].l==mid){
                a[i].l=mid+1;
                stl=i-1,str=i;
            }
            if(a[i].r==mid){
                a[i].r=mid-1;
                stl=i,str=i+1;
            }
        }
            while(a[stl].l+a[str].r<=sum){
                if(mid-a[stl].l>a[str].r-mid){
                    if(a[stl].w!=a[str].w){
                        ans+=a[str].r-mid;
                    }
                    a[stl].r=mid-a[str].r+mid;
                    str+=1;
                }
                if(mid-a[stl].l<a[str].r-mid){
                    if(a[stl].w!=a[str].w){
                        ans+=mid-a[stl].l;
                    }
                    a[str].l=mid+mid-a[stl].l+1;
                    stl-=1;
                }
            }
            cout<<ans;
	}
	return 0;
}
