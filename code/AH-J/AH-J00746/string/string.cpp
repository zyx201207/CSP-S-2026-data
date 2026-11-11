#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
unsigned long long sum;
int n,last,l=1,r;
int a[200005];
char c[200005],lc;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;r=n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        //scanf("%d%c",a+i,c+i);
    }while(r>l){
        if(last!=0){
            if(last<0){
                if(c[l]!=lc){
                    if(a[l]>-last){
                        sum-=last;
                        lc=c[l];
                        r--;
                    }
                    else{
                        sum+=a[l];
                        l++;
                    }last=a[l]+last;
                }else{
                    last=a[l]+last;
                    if(last>0)r--;
                    if(last<0)l++;
                    else r--,l++;
                }
            }else{
                if(c[r]!=lc){
                    if(a[r]>last){
                        sum+=last;
                        lc=c[r];
                        l++;
                    }else{
                        sum+=a[r];
                        r--;
                    }last=last-a[r];
                }else{
                    last=last-a[r];
                    if(last>0)r--;
                    if(last<0)l++;
                    else r--,l++;
                }
            }
            continue;
        }
        if(c[l]!=c[r]){
            last=a[l]-a[r];
            if(a[l]>a[r]){
                sum+=a[r];
                lc=c[l];
                r--;
            }
            else{
                sum+=a[l];
                lc=c[r];
                l++;
            }
        }else{
            last=a[l]-a[r];
            if(last>0)r--;
            if(last<0)l++;
            else r--,l++;
        }
    }
    cout<<sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
