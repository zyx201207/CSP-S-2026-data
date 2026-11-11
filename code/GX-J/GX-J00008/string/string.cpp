 #include <bits/stdc++.h>
using namespace std;

int a[100005];
string s[100005];

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    int n;
    cin >>n;

    for (int i = 0;i <n;i++){
        cin >> a[i];
        cin >> s[i];
    }

    string b[1000000000000005];

    for (int i = 0; i <n;i++){
        for (int j = 0;j<a[i];j++){
            b[j+i] = s[i];
        }
    }


    int cnt = 0,head = 0,e=n*n;

    if(n<=1)
        cout << s;
    while(head >= e){
        if (!(b[head] == b[e]))
            cnt++;
        head++;
        e--;
    }
    cout << cnt;
    return 0;
}
