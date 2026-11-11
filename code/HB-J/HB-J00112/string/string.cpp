#include <bits/stdc++.h>
using namespace std;

struct{
    int num;
    char s;
}a[200005];

int n;
long long ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;//cout << ans;
    for(int i=1;i<=n;i++){
        cin >> a[i].num >> a[i].s;
    }
    /*for(i=1;i<=n/2;i++){
        int j=n-i+1;
        if(a[i].s == a[j].s)continue;
            ans+=min(a[i].num,a[j].num);
            if(a[i].num != a[j].num)


        }
    }*/
    for(int i=1,j=n;i<=j;){
        if(a[i].s != a[j].s){
            if(a[i].num >a[j].num){
                a[i].num-=a[j].num;
                ans+=a[j].num;
                j--;

            }
            else if(a[i].num == a[j].num){

                ans+=a[i].num;j--;i++;
            }
            else {
                a[j].num-=a[i].num;
                ans+=a[i].num;
                i++;

            }
        }
        //aaaaaaaaaaaaaaaaaaaaaa
        else {
            if(a[i].num >a[j].num){
                a[i].num-=a[j].num;

                j--;

            }
            else if(a[i].num == a[j].num){
            j--;i++;
            }
            else {
                a[j].num-=a[i].num;

                i++;
            }
        }

    }

    cout << ans;
    return 0;

    }
