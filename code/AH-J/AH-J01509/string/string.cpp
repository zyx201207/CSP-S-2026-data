#include<bits/stdc++.h>
using namespace std;
int n;
struct s{
    char english;
    long long number;
}a[200005];
long long sum = 0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i = 1;i<=n;i++){
        cin >> a[i].number >> a[i].english;
    }
    int left = 1,right = n;
    while(left < right){
        int minn = min(a[left].number,a[right].number);
        if(a[left].english != a[right].english){
            sum += minn;
        }
        a[left].number -= minn;
        a[right].number -= minn;
        if(a[left].number == 0){
            left++;
        }
        if(a[right].number == 0){
            right--;
        }
    }
    cout << sum;
    return 0;
}

