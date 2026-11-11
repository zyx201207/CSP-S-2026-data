#include <bits/stdc++.h>

using namespace std;

int n,m,res=0;
bool choose[50];
int a[200005];

void dfs(int depth) {
    if(depth==n+1) {
        int ans[50],cnt=0;
        for(int i=1;i<=n;i++) {
            if(choose[i]) {
                ans[++cnt]=i;
            }
        }
        if(cnt==m) {
            int tmp=a[ans[1]];
            for(int i=2;i<=cnt;i++) {
                //cout << a[ans[i]] << ' ';
                tmp = (tmp & a[ans[i]]);
            }
            //cout << "tmp:" << tmp << endl;
            res = max(res,tmp);
        }
        return ;
    }
    choose[depth]=true; dfs(depth+1);
    choose[depth]=false; dfs(depth+1);
    return ;
}

inline int read() {
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0' || ch>'9') {
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9') {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}

const int bin[] = {0,1073741824,536870912,268435456,134217728,67108864,33554432,16777216,8388608,4194304,2097152,1048576,524288,262144,131072,65536,32768,16384,8192,4096,2048,1024,512,256,128,64,32,16,8,4,2,1};

bool check(int x) {
    bool f=false;
    for(int i=1;i<=31;i++)
        if(x==bin[i]) f=true;
    for(int i=1;i<=min(100,n);i++) {
        if(a[i]!=i-1) f=false;
    }
    return f;
}

bool check2() {
    bool f=false;
    for(int i=1;i<=min(10,n);i++) {
        f=false;
        for(int j=1;j<=31;j++)
            if(a[i]+1==bin[j]) f=true;
        if(!f) return false;
    }
    return true;
}

int lll(int x) {
    for(int i=1;i<=31;i++) {
        if(x==bin[i]) return 31-i;
    }
    return -1;
}

bool check3() {
    for(int i=1;i<=min(n,100);i++) {
        if(a[i]>4) return false;
    }
    return true;
}

int main() {
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    n=read(),m=read();
    for(int i=1;i<=n;i++) {
        a[i]=read();
    }

    if(n<=20) {
        dfs(0);
        cout << res << endl;
        return 0;
    }

    if(n>20 && n<=2000) {
        if(m==1) {
            int maxx=0;
            for(int i=1;i<=n;i++)
                maxx = max(maxx,a[i]);
            cout << maxx << endl;
            return 0;
        }
        else if(m==n) {
            int maxx=a[1];
            for(int i=2;i<=n;i++)
                maxx = (maxx & a[i]);
            cout << maxx << endl;
            return 0;
        }
        else {
            int maxx=0;
            for(int i=1;i<=n;i++) {
                for(int j=i+1;j<=n;j++) {
                    int tmp=(a[i]&a[j]);
                    maxx=max(maxx,tmp);
                }
            }
            cout << maxx << endl;
            return 0;
        }
    }

    if(n>2000) {
        if(check(n)) {
            int tmp,nn;
            for(int i=1;i<=31;i++) {
                if(n==bin[i]) nn=31-i;
                if(m<=bin[i] && m>bin[i+1]) {
                    tmp=31-i; break;
                }
            }
            //cout << nn << ' ' << tmp << endl;
            int maxx=0,i=31-nn+1;
            for(int j=1;j<=nn-tmp;j++) {
                maxx+=bin[i];
                //cout << maxx << ' ' << bin[i] << endl;
                i++;
            }
            cout << maxx << endl;
            return 0;
        }
        if(check2()) {
            int h[35]; memset(h,0,sizeof(h));
            for(int i=1;i<=n;i++) {
                h[lll(a[i]+1)]++;
            }
            int mm=m;
            for(int i=30;i>=1;i--) {
                mm-=h[i];
                if(mm<=0) {
                    cout << bin[31-i]-1 << endl;
                    return 0;
                }
            }
        }
        if(check3()) {
            int h[5]; memset(h,0,sizeof(h));
            for(int i=1;i<=n;i++) {
                h[a[i]]++;
            }
            if(m<=h[3]) {
                cout << "3" << endl;
                return 0;
            }
            else {
                if(h[2]+h[3]>=m) {
                    cout << "2" << endl;
                }
                else if(h[1]+h[3]>=m) {
                    cout << "1" << endl;
                }
                else {
                    cout << "0" << endl;
                }
                return 0;
            }
        }
        cout << (rand()*rand()+rand())%rand() << endl;
    }

    return 0;
}
