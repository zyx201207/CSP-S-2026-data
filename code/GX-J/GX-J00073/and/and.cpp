#include<bits/stdc++.h>
using namespace std;
int a[10100];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin >> n >> m;
    const int M = m;
    int b[M];
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    for(int i = 0;i < n;i++){
        for(int j = i;j<n;i++)
        if(a[j] < a[j+1]){
            int l = a[j];
            a[j] = a[j+1];
            a[j+1] = l;
        }
    }
    int y;
    for(int i = 0;i < m;i++){
        int h = i;
        string er;
        while(i > 0){
             er += i % 2;
            i /= 2;
        }
        int erlen= er.length();
        for(int i = 0;i < erlen;i++){
            char q = er[i];
            er[i] = er[erlen-1-i];
            er[erlen-1-i] = q;
        }
        b[i] = (int)er;
        for(int i = 2;i <= m;i++){
            y = a[0] & a[1];
            y = y & i;
        }
    }
    cout << y << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
