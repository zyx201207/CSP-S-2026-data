#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n;
long long s,ans;
struct node{
    long long ll,rr;
    char c;
};
long long l[N];
char a[N];
vector<node>L;
vector<node>R;

void f(){
    long long mid=s/2;
    long long sum=0,num=1;
    for(int i=1;i<=n;i++){
        sum+=l[i];
        if(sum<=mid){
            if(L.size()>=1){
                if(L[L.size()-1].c==a[i]){L[L.size()-1].rr=sum; continue;}

            }
            L.push_back(node{num,sum,a[i]});
        }
        else if(num<=mid&&sum>mid){
            if(L.size()>1){
                if(L[L.size()-1].c==a[i]) L[L.size()-1].rr=mid;
                else L.push_back(node{num,mid,a[i]});
            }
            R.push_back(node{mid+1,sum,a[i]});
        }
        else{
            if(R.size()>=1){
                if(R[R.size()-1].c==a[i]){R[R.size()-1].rr=sum; continue;}

            }
            R.push_back(node{num,sum,a[i]});
        }
        num=sum+1;
    }
    //for(int i=0;i<L.size();i++) cout<<L[i].ll<<" "<<L[i].rr<<" "<<L[i].c<<"\n";
    //cout<<"\n";
    //for(int i=0;i<R.size();i++) cout<<R[i].ll<<" "<<R[i].rr<<" "<<R[i].c<<"\n";
    long long j=R.size()-1;
    //cout<<j<<"\n";
    for(int i=0;i<L.size();i++){
        long long x=L[i].ll,yy=s-R[j].ll+1;
        long long y=L[i].rr,xx=s-R[j].rr+1;
        //cout<<x<<" "<<y<<"\n"<<xx<<" "<<yy<<"\n";
        char cl=L[i].c,co=R[j].c;
        if(x==xx&&y==yy){
            if(co==cl){j--; continue;}
            else{j--,ans+=y-x+1; continue;}
        }
        else if(x==xx){
            if(y>yy){
                if(cl==co);
                else ans+=yy-xx+1;
                j--;
                L[i].ll=xx+1;
                i--;
            }
            else{
                if(cl==co);
                else ans+=y-x+1;
                R[j].ll=s-x+1;
            }
        }
    }
}

void ff(){
    long long mid=s/2+1;
    long long sum=0,num=1;
    for(int i=1;i<=n;i++){
        sum+=l[i];
        if(sum<mid){
            if(L.size()>=1){
                if(L[L.size()-1].c==a[i]) L[L.size()-1].rr=sum;
                continue;
            }
            L.push_back(node{num,sum,a[i]});
        }
        else if(num<mid&&sum>mid){
            if(L.size()>=1){
                if(L[L.size()-1].c==a[i]) L[L.size()-1].rr=mid-1;
            }
            else L.push_back(node{num,mid-1,a[i]});
            R.push_back(node{mid+1,sum,a[i]});
        }
        else{
            if(sum==mid) continue;
            if(num==mid) num++;
            if(R.size()>1){
                if(R[R.size()-1].c==a[i]) R[R.size()-1].rr=sum;
                continue;
            }
            R.push_back(node{num,sum,a[i]});
        }
        num=sum+1;
    }
    long long j=R.size()-1;
    for(int i=0;i<L.size();i++){
        long long x=L[i].ll,yy=s-R[j].ll+1;
        long long y=L[i].rr,xx=s-R[j].rr+1;
        //cout<<x<<" "<<y<<"\n"<<xx<<" "<<yy<<"\n";
        char cl=L[i].c,co=R[j].c;
        if(x==xx&&y==yy){
            if(co==cl){j--; continue;}
            else{j--,ans+=y-x+1; continue;}
        }
        else if(x==xx){
            if(y>yy){
                if(cl==co);
                else ans+=yy-xx+1;
                j--;
                L[i].ll=xx+1;
                i--;
            }
            else{
                if(cl==co);
                else ans+=y-x+1;
                R[j].ll=s-x+1;
            }
        }
    }
}

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>l[i]>>a[i];
        s+=l[i];
        //cout<<l[i]<<a[i]<<"\n";
    }
    if(s%2==0) f();
    else ff();
    cout<<ans<<"\n";
    return 0;
}
