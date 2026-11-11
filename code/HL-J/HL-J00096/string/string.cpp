#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n;
long long sum,ant;
char l[N],a[N];
long long b[N],c[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> b[i] >> l[i];
        sum+=b[i];
    }
    long long len=sum/2;
	long long k=0;
    while(len){
        if(b[k]<=len){
            a[k]=l[k];
            c[k]=b[k];
            len-=b[k];
        }else{
            a[k]=l[k];
            c[k]=len;
            b[k]-=len;
            len=0;
        }
        k++;
    } 
    if(sum%2==1){
        a[k]=l[k];
        c[k]=1;
		b[k]-=1;
        k++;
    }
    for(int i=k;i<=n;i++){
        a[i]=l[i-1];
        c[i]=b[i-1];
    }
//    for(int i=0;i<=n;i++){
//        cout << a[i] << " ";
//    }cout << endl;
//    for(int i=0;i<=n;i++){
//        cout << c[i] << " ";
//    }cout << endl;
    int l=0,r=n;
    while(l<n){
        if(a[l]==a[r]){
            if(c[l]>c[r]){
                c[l]-=c[r];
                c[r]=0;
                r--;
            }else if(c[l]<c[r]){
                c[r]-=c[l];
                c[l]=0;
                l++;
            }else{
                c[r]-=c[l];
                c[l]=0;
                l++;
                r--;
            }
        }else{
            if(c[l]>c[r]){
                ant+=c[l]-c[r];
                c[l]-=c[r];
                c[r]=0;
                r--;
            }else if(c[l]<c[r]){
                ant+=c[r]-c[l];
                c[r]-=c[l];
                c[l]=0;
                l++;
            }else{
                ant+=c[l];
                c[r]-=c[l];
                c[l]=0;
                l++;
                r--;
            }
        }
    }
    cout << ant;
    return 0;
}


