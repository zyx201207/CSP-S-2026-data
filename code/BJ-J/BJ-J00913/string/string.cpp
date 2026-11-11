#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,p[200007],lb,rb,ans;
char c[200007],lc,rc;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;++i){
        cin >> p[i] >> c[i];
    }
    lb = 1,rb = n;
    while(lb<rb){
        lc = c[lb],rc = c[rb];
        if(p[lb]<=p[rb]){
            if(lc!=rc)ans += p[lb];
            p[rb]-=p[lb];
            ++lb;
        }else{
            if(lc!=rc)ans += p[rb];
            p[lb]-=p[rb];
            --rb;
        }
    }
    cout << ans;
    return 0;
}

/*
闲来无事，随便统计一下。
代码长度（不计算本条注释）：604B
字符统计（不计算本条注释）：
\n:28
(空格):187
!:2
":8
#:2
(:8
):8
+:8
,:12
-:4
.:3
/:1
0:9
1:2
2:2
7:2
;:19
<:6
=:13
>:7
[:14
]:14
a:8
b:19
c:19
d:7
e:14
f:7
g:6
h:3
i:24
l:18
m:2
n:28
o:8
p:13
r:22
s:15
t:14
u:6
w:2
{:5
}:5
*/
